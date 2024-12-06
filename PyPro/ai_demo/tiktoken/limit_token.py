from openai import OpenAI
import tiktoken

client = OpenAI()

#这是API请求和响应的总token数量限制,对于GPT-4模型，每个请求，OpenAI API限制为4096个token
MAX_TOKENS = 8 #设置最大token数量
#这是我们预留给模型响应的token数量，我们需要在计算对话的最大token数量时考虑减去这个值，以确保有足够的空间来容纳模型的响应
MAX_RESPONSE_TOKENS = 6 #设置响应中预留的最大token数量
encoder = tiktoken.encoding_for_model("gpt-4")

def count_tokens(text):
    #使用tiktoken编码器对文本进行编码
    #将输入的文本text转换为对应的token列表,具体来说，它使用tiktoken库中的编码器将文本进行编码，以便后续处理
    tokens = encoder.encode(text)
    #统计文本中的token数量
    return len(tokens)

#假设MAX_TOKENS为4096，而MAX_RESPONSE_TOKENS为500，那么
#我们希望对话历史的token数量不要超过3596(4096-500)个token
#这样当我们发送对话历史给OpenAI API时，仍然有500个token的空间来容纳模型的响应
def manage_token_limit(messages):
    current_tokens = count_tokens(messages)
    if current_tokens > (MAX_TOKENS - MAX_RESPONSE_TOKENS):
        print(f"当前会话token数量为: {current_tokens}，已经超过了限制{MAX_TOKENS - MAX_RESPONSE_TOKENS}，请删除一些历史记录")
        return False
    return True

def get_gpt_response(messages):
    #获取GPT-4的响应
    response = client.chat.completions.create(
        model="gpt-4",
        messages=messages
    )
    return response.choices[0].message.content.strip()

def main():
    messages = []

    print("chat with GPT-4, input 'exit' to quit")
    while True:
        user_input = input("用户:")
        if user_input.lower() == 'exit':
            print("感谢您的使用，再见！")
            break

        #将用户输入添加到聊天记录中
        messages.append({"role": "user", "content": user_input})

        #管理消息列表以确保总token数量不超过限制
        if not manage_token_limit(user_input):
            continue

        response = get_gpt_response(messages)
        print(f"GPT: {response}")

        messages.append({"role": "assistant", "content": response})

if __name__ == '__main__':
    main()