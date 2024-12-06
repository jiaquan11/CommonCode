from openai import OpenAI

client = OpenAI()

response = client.chat.completions.create(
    model="gpt-4o",
    response_format={"type" : "json_object"},
    messages=[
        {"role": "user", "content": "你是一个助手，请用中文输出JSON"},
        {"role": "user", "content": "2022年世界杯冠军是哪个队伍?"}
    ]
)
print(response.choices[0].message.content)