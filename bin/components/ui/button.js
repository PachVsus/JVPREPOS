import * as React from "react";

export const Button = ({ className, ...props }) => {
  return (
    <button
      className={`bg-blue-500 text-white p-2 rounded ${className}`}
      {...props}
    />
  );
};
