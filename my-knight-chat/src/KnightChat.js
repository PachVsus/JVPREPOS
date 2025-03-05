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
        ,/|\,
      //|O|\\
     // | | \\
     || | | ||
     || | | ||
     || | | ||
     || | | ||
     || | | ||
     || | | ||
     || | | ||
     ||_| |_||
     || | | ||
     ||_| |_||
    /_|_|_|_|_\
   (___________)
    |   _   |
   /|  | |  |\
  / |  | |  | \
 /  |__|_|__|  \
(    |     |    )
 \   |     |   /
  \__|_____|__/
    (_______)
   /_________\
  (___________)
 (_____________)
  |___________|
  |___________|
   |  |   |  |
   |  |   |  |
   |  |   |  |
   |__|   |__|
  (___)   (___)

  `;

  const sendMessage = async () => {
    if (!input.trim()) return;

    const newMessages = [...messages, { text: input, sender: "user" }];
    setMessages(newMessages);
    setInput("");

    try {
      const response = await axios.post("http://localhost:11434/api/generate", {
        model: "mistral",
        prompt: `You are a medieval knight. Respond in old-style medieval speech. User: "${input}"`,
        stream: false
      });

      const botResponse = response.data.response || "I have no words, traveler...";

      setMessages([...newMessages, { text: botResponse, sender: "knight" }]);
      setPosition((prev) => prev + (Math.random() > 0.5 ? 20 : -20));

    } catch (error) {
      console.error("Error fetching AI response:", error);
      setMessages([...newMessages, { text: "The kingdom’s magic is weak, try again later.", sender: "knight" }]);
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