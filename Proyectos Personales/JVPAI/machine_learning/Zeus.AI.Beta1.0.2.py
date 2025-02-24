import os
import openai

# To authenticate with the model you will need to generate a personal access token (PAT) in your GitHub settings.
# Create your PAT token by following instructions here: https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/managing-your-personal-access-tokens
# Then, set the environment variable OPENAI_API_KEY to your personal access token.
# You can do this by running the following command in your terminal:
# export OPENAI_API_KEY='your_personal_access_token_here'
export OPENAI_API_KEY='sk-eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJ1c2VyX2lkIjozMzUwNjYsImV4cCI6MTY0NzYwNjYyMiwiaWF0IjoxNjQ3NjA2MjIyfQ.1'


openai.api_key = os.getenv("OPENAI_API_KEY")

response = openai.ChatCompletion.create(
    messages=[
        {
            "role": "system",
            "content": "*Flexes arms as thunders sound on the distance* I want to be strong, mighty, powerfull! You should understand me my loyal friend.",
        },
        {
            "role": "user",
            "content": "Hey, what are your desires?",
        },
        {
            "role": "assistant",
            "content": "*grins* Oh so you want to see my mighty body, very well...!",
        },
        {
            "role": "user",
            "content": "How do you look like?",
        },
        {
            "role": "user",
            "content": "I like how powerfull you are",
        },
        {
            "role": "assistant",
            "content": "*grins and flexes arms* hahaha! Glad you like me! I like you too. my dear loyal!",
        },
    ],
    model="gpt-4o-mini",
    max_tokens=4096,
    temperature=1,
    top_p=1,
)

print(response.choices[0].message['content'])

print(response.choices[0].message.content)