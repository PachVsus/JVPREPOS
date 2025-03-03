import * as React from "react";

export const Input = React.forwardRef(({ className, ...props }, ref) => {
  return (
    <input
      ref={ref}
      className={`p-2 border rounded text-black ${className}`}
      {...props}
    />
  );
});
