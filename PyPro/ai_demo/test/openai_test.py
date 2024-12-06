import os
from datetime import datetime

from openai import OpenAI

client = OpenAI(
    api_key=os.getenv('OPENAI_API_KEY'),
    base_url= os.getenv('OPENAI_BASE_URL')
)

#Create a chat completion
# start_time = datetime.now()
# response = client.chat.completions.create(
#     model="gpt-4o",
#     messages=[
#         #{"role": "system", "content": "你是一个专业的翻译助手，能将输入的中文翻译成英文。"},
#         {"role": "user", "content": "输出Python如何计算程序执行时间"}
#     ]
# )
# end_time = datetime.now()
#
# #Print the response
# print(response.choices[0].message.content)
# execution_time = (end_time - start_time).total_seconds()
# print(f'执行时间: {execution_time:.5f}秒')

def stream_completion_response(prompt):
    response = client.chat.completions.create(
        model="gpt-4o",
        messages=[
            #{"role": "system", "content": "你是一个专业的翻译助手，能将输入的中文翻译成英文。"},
            {"role": "user", "content": prompt}
        ],
        stream=True
    )
    #逐个处理并打印接收到的token
    for chunk in response:
        chunk_message = chunk.choices[0].delta.content if chunk.choices and chunk.choices[0].delta.content else ''
        print(chunk_message, end='')

    print()
#示例调用
# prompt = "输出Python如何计算程序执行时间"
# stream_completion_response(prompt)

#简洁控制台用户循环交互示例
while True:
    user_input = input("请输入您的内容或者输入'退出'来结束程序: ")
    if user_input.lower() == '退出':
        print("感谢您的使用，再见！")
        break
    else:
        print('=============AI Response=============')
        stream_completion_response(user_input)
        #print(f"你输入了: {user_input}")