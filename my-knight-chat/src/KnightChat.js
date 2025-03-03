import { useState } from "react";
import { motion } from "framer-motion";
import axios from "axios";
import { Input } from "./components/ui/input";
import { Button } from "./components/ui/button";
import { Card, CardContent } from "./components/ui/card";

export default function KnightChat() {
  const [messages, setMessages] = useState([]);
  const [input, setInput] = useState("");
  const [position, setPosition] = useState(0);

  const asciiKnight = `
      .-\"\"\"\"-.
     / -   -  \\
    |  o   o  |
    |   \_/   |
     \   -   /
      '-...-'
    / |     | \\
   /  |     |  \\
  /   |-----|   \\
  `;

  const sendMessage = async () => {
    if (!input.trim()) return;

    const newMessages = [...messages, { text: input, sender: "user" }];
    setMessages(newMessages);
    setInput("");

    try {
      const response = await axios.post(
        "https://api.openai.com/v1/chat/completions",
        {
          model: "gpt-3.5-turbo",
          messages: [
            { role: "system", content: "You are a medieval knight AI who gives quest-related responses." },
            { role: "user", content: input }
          ]
        },
        {
          headers: {
            "Authorization": `Bearer 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`,
            "Content-Type": "application/json"
          }
        }
      );

      const botResponse = response.data.choices[0].message.content;

      setMessages([...newMessages, { text: botResponse, sender: "knight" }]);
      setPosition((prev) => prev + (Math.random() > 0.5 ? 20 : -20));
    } catch (error) {
      console.error("Error fetching AI response:", error);
      setMessages([...newMessages, { text: "I am lost in thought, try again later.", sender: "knight" }]);
    }
  };

  return (
    <div className="flex flex-col items-center p-6 bg-gray-900 text-white h-screen">
      <h1 className="text-2xl font-bold">ASCII Knight Chat</h1>
      <Card className="w-full max-w-md mt-4">
        <CardContent className="p-4 h-80 overflow-auto bg-gray-800">
          {messages.map((msg, index) => (
            <div key={index} className={`mt-2 ${msg.sender === "user" ? "text-right" : "text-left"}`}>
              <span className={msg.sender === "user" ? "text-blue-400" : "text-yellow-400"}>
                {msg.text}
              </span>
            </div>
          ))}
        </CardContent>
      </Card>
      <motion.pre animate={{ x: position }} transition={{ type: "spring", stiffness: 100 }}>
        {asciiKnight}
      </motion.pre>
      <div className="flex gap-2 mt-4 w-full max-w-md">
        <Input
          value={input}
          onChange={(e) => setInput(e.target.value)}
          placeholder="Speak to the knight..."
          className="flex-grow"
        />
        <Button onClick={sendMessage}>Send</Button>
      </div>
    </div>
  );
}
