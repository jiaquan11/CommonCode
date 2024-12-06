from openai import OpenAI

client = OpenAI()

for i in range(3):
    response = client.chat.completions.create(
        model="gpt-4o",
        #对于三个请求中的每一个，使用相同的seed参数，以确保每个请求的输出都是相同的
        seed = 42,
        temperature=0.7,
        max_tokens=50,
        messages=[
            {"role": "user", "content": "你是一个生成故事机器人"},
            {"role": "user", "content": "告诉我一个关于宇宙是如何开始的故事?"}
        ]
    )
    print(f'故事版本{i+1}: {response.choices[0].message.content}')
    del response