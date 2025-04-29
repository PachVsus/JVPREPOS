import * as React from "react";

export const Card = ({ className, children }) => {
  return (
    <div className={`border p-4 rounded-lg bg-gray-800 ${className}`}>
      {children}
    </div>
  );
};

export const CardContent = ({ className, children }) => {
  return <div className={`p-4 ${className}`}>{children}</div>;
};
