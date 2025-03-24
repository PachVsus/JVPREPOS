import React, { useState, useEffect } from "react";
import { motion, AnimatePresence } from "framer-motion";

const letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,:!?'-";

const Flap = ({ char, interval = 30 }) => {
  const [displayChar, setDisplayChar] = useState(" ");

  useEffect(() => {
    if (char === displayChar) return;

    let currentIndex = letters.indexOf(displayChar);
    const targetIndex = letters.indexOf(char);
    let step = 0;

    const flip = setInterval(() => {
      currentIndex = (currentIndex + 1) % letters.length;
      setDisplayChar(letters[currentIndex]);
      step++;
      if (letters[currentIndex] === char || step > letters.length) {
        clearInterval(flip);
      }
    }, interval);

    return () => clearInterval(flip);
  }, [char]);

  return (
    <div className="w-16 h-24 bg-black text-white text-5xl flex items-center justify-center rounded-xl shadow-lg border border-gray-700 font-mono transition-transform duration-200">
      <AnimatePresence mode="wait">
        <motion.div
          key={displayChar}
          initial={{ rotateX: -90, opacity: 0 }}
          animate={{ rotateX: 0, opacity: 1 }}
          exit={{ rotateX: 90, opacity: 0 }}
          transition={{ duration: 0.2 }}
        >
          {displayChar}
        </motion.div>
      </AnimatePresence>
    </div>
  );
};

const SplitFlapDisplay = ({ text }) => {
  return (
    <div className="flex gap-2 p-4 flex-wrap justify-center">
      {text.split("").map((char, idx) => (
        <Flap key={idx} char={char.toUpperCase()} />
      ))}
    </div>
  );
};

export default function App() {
  const [text, setText] = useState("HELLO WORLD");
  const [input, setInput] = useState("");

  useEffect(() => {
    const messages = [
      "HELLO WORLD",
      "WELCOME HOME",
      "ENJOY THE SHOW",
      "DEPARTURE BOARD",
      "OPENAI SPLIT FLAP"
    ];
    let i = 0;
    const interval = setInterval(() => {
      if (!input) {
        i = (i + 1) % messages.length;
        setText(messages[i]);
      }
    }, 4000);
    return () => clearInterval(interval);
  }, [input]);

  const handleInputChange = (e) => {
    const value = e.target.value.toUpperCase().slice(0, 20);
    setInput(value);
    setText(value);
  };

  return (
    <div className="min-h-screen bg-gradient-to-br from-gray-900 to-black flex flex-col items-center justify-center text-white px-4">
      <h1 className="text-3xl font-bold mb-6">Virtual Split-Flap Display</h1>
      <SplitFlapDisplay text={text} />
      <input
        type="text"
        value={input}
        onChange={handleInputChange}
        placeholder="Type your own message..."
        className="mt-8 p-3 rounded-md text-black text-lg w-full max-w-md shadow-md focus:outline-none"
      />
      <p className="mt-4 text-gray-400 text-sm">Displays your input live. Max 20 characters.</p>
    </div>
  );
}