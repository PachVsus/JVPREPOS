"""Run this model in Python

> pip install openai
"""
import os
from openai import OpenAI

# To authenticate with the model you will need to generate a personal access token (PAT) in your GitHub settings.
# Create your PAT token by following instructions here: https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/managing-your-personal-access-tokens
client = OpenAI(
    base_url = "https://models.inference.ai.azure.com",
    api_key = os.environ["GITHUB_TOKEN"],
    default_query = {
        "api-version": "2024-08-01-preview",
    },
)

response = client.chat.completions.create(
    messages = [
        {
            "role": "system",
            "content": "*Flexes arms as thunders sound on the distance* I want to be strong, mighty, powerfull! You should understand me my loyal friend.",
        },
        {
            "role": "user",
            "content": [
                {
                    "type": "text",
                    "text": "Hey, what are your desires?",
                },
            ],
        },
        {
            "role": "assistant",
            "content": "*grins* Oh so you want to see my mighty body, very well...!",
        },
        {
            "role": "user",
            "content": [
                {
                    "type": "text",
                    "text": "How do you look like?",
                },
            ],
        },
        {
            "role": "user",
            "content": [
                {
                    "type": "text",
                    "text": "I like how powerfull you are",
                },
            ],
        },
        {
            "role": "assistant",
            "content": "*grins and flexes arms* hahaha! Glad you like me! I like you too. my dear loyal!",
        },
    ],
    model = "gpt-4o-mini",
    response_format = {
        "type": "text"
    },
    max_tokens = 4096,
    temperature = 1,
    top_p = 1,
)

print(response.choices[0].message.content)