import { useState } from "react";
import { motion } from "framer-motion";
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

  const sendMessage = () => {
    if (!input.trim()) return;
    
    const newMessages = [...messages, { text: input, sender: "user" }];
    setMessages(newMessages);
    setInput("");
  
    // Smart responses based on keywords
    const lowerInput = input.toLowerCase();
    let response = "I do not understand, traveler...";
  
    if (lowerInput.includes("hello") || lowerInput.includes("hi")) {
      response = "Greetings, noble warrior!";
    } else if (lowerInput.includes("treasure")) {
      response = "Legends speak of a golden chalice hidden in the mountains.";
    } else if (lowerInput.includes("king")) {
      response = "The king awaits you in the grand castle!";
    } else if (lowerInput.includes("battle") || lowerInput.includes("fight")) {
      response = "Sharpen your sword! A battle is near!";
    } else if (lowerInput.includes("help")) {
      response = "Fear not, I shall guide you on your quest.";
    } else if (lowerInput.includes("enemy")) {
      response = "Beware, for dark forces are gathering!";
    } else if (lowerInput.includes("quest")) {
      response = "Your quest is to restore peace to the kingdom!";
    }
  
    setTimeout(() => {
      setMessages((prevMessages) => [...prevMessages, { text: response, sender: "knight" }]);
      setPosition((prev) => prev + (Math.random() > 0.5 ? 20 : -20));
    }, 1000);
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
