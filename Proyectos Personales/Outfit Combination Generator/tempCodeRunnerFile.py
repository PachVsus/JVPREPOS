# Outfit Generator - Python (Tkinter + JSON based wardrobe)

import tkinter as tk
from tkinter import filedialog, messagebox, ttk
import json
import os
import random
from PIL import Image, ImageTk

# Load or initialize wardrobe file
WARDROBE_FILE = "wardrobe.json"
def load_wardrobe():
    if os.path.exists(WARDROBE_FILE):
        with open(WARDROBE_FILE, 'r') as f:
            return json.load(f)
    return []

def save_wardrobe(data):
    with open(WARDROBE_FILE, 'w') as f:
        json.dump(data, f, indent=4)

wardrobe = load_wardrobe()

# Main app window
class OutfitApp(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Outfit Combination Generator")
        self.geometry("800x600")
        self.configure(bg='white')

        # Header and controls
        tk.Button(self, text="Upload Clothes to Wardrobe", command=self.open_upload_popup).pack(pady=10)
        tk.Button(self, text="Manage Wardrobe", command=self.open_wardrobe_manager).pack(pady=5)
        tk.Button(self, text="Generate Random Outfit", command=self.generate_outfit).pack(pady=10)

        # Outfit display
        self.outfit_frame = tk.LabelFrame(self, text="Today’s Outfit", padx=10, pady=10)
        self.outfit_frame.pack(pady=20, fill="both", expand=True)
        self.output_label = tk.Label(self.outfit_frame, text="Outfit preview will go here")
        self.output_label.pack()

    def open_upload_popup(self):
        UploadPopup(self)

    def open_wardrobe_manager(self):
        WardrobeManager(self)

    def generate_outfit(self):
        categories = ["Shirt", "Jacket", "Pants", "Underwear", "Shoes", "Watch", "Cap"]
        selected = {}
        for cat in categories:
            items = [item for item in wardrobe if item["type"] == cat]
            if items:
                selected[cat] = random.choice(items)

        result = ""
        for cat in categories:
            if cat in selected:
                result += f"{cat}: {selected[cat]['name']} ({selected[cat]['style']})\n"
            else:
                result += f"{cat}: [No item available]\n"

        self.output_label.config(text=result)

# Popup to upload new cloth
class UploadPopup(tk.Toplevel):
    def __init__(self, master):
        super().__init__(master)
        self.title("Add a New Cloth to Your Wardrobe")
        self.geometry("400x400")

        self.photo_path = None

        tk.Button(self, text="Upload Photo", command=self.upload_photo).pack(pady=5)
        tk.Label(self, text="Write name of cloth:").pack()
        self.name_entry = tk.Entry(self)
        self.name_entry.pack()

        tk.Label(self, text="Select Type:").pack()
        self.type_select = ttk.Combobox(self, values=["Shirt", "Jacket", "Pants", "Underwear", "Shoes", "Watch", "Cap"])
        self.type_select.pack()

        tk.Label(self, text="Main Color:").pack()
        self.color_main = tk.Entry(self)
        self.color_main.pack()

        tk.Label(self, text="Secondary Color (optional):").pack()
        self.color_secondary = tk.Entry(self)
        self.color_secondary.pack()

        tk.Label(self, text="Select Style:").pack()
        self.style_select = ttk.Combobox(self, values=["Casual", "Rock and Roll", "Glamrock", "Jock", "Streetwear", "Grunge", "Punk", "Classic", "Techwear", "Business Casual", "Minimalist", "Preppy", "Athleisure", "Goth", "K-pop Inspired", "Boho", "Formal", "Fantasy Casual"])
        self.style_select.pack()

        tk.Button(self, text="Save", command=self.save_cloth).pack(pady=10)
        tk.Button(self, text="Cancel", command=self.destroy).pack()

    def upload_photo(self):
        path = filedialog.askopenfilename(filetypes=[("Image files", "*.jpg *.jpeg *.png")])
        if path:
            self.photo_path = path
            messagebox.showinfo("Uploaded", f"Photo uploaded: {os.path.basename(path)}")

    def save_cloth(self):
        if not self.photo_path or not self.name_entry.get() or not self.type_select.get():
            messagebox.showerror("Missing Info", "Please fill out all required fields.")
            return

        cloth = {
            "name": self.name_entry.get(),
            "type": self.type_select.get(),
            "main_color": self.color_main.get(),
            "secondary_color": self.color_secondary.get(),
            "style": self.style_select.get(),
            "image_path": self.photo_path
        }
        wardrobe.append(cloth)
        save_wardrobe(wardrobe)
        messagebox.showinfo("Saved", "Cloth saved to wardrobe.")
        self.destroy()

# Manager to edit/delete clothes
class WardrobeManager(tk.Toplevel):
    def __init__(self, master):
        super().__init__(master)
        self.title("Manage Wardrobe Memory")
        self.geometry("500x500")
        self.refresh_list()

    def refresh_list(self):
        for widget in self.winfo_children():
            widget.destroy()

        for i, item in enumerate(wardrobe):
            frame = tk.Frame(self, pady=5)
            frame.pack(fill="x")

            tk.Label(frame, text=f"{item['type']}: {item['name']} [{item['style']}]").pack(side="left")
            tk.Button(frame, text="Edit", command=lambda i=i: self.edit_item(i)).pack(side="right")
            tk.Button(frame, text="Delete", command=lambda i=i: self.delete_item(i)).pack(side="right")

    def edit_item(self, index):
        EditPopup(self, index)

    def delete_item(self, index):
        if messagebox.askyesno("Confirm Delete", "Delete this item?"):
            del wardrobe[index]
            save_wardrobe(wardrobe)
            self.refresh_list()

class EditPopup(UploadPopup):
    def __init__(self, manager, index):
        super().__init__(manager)
        self.title("Edit Cloth")
        self.index = index
        data = wardrobe[index]
        self.name_entry.insert(0, data["name"])
        self.type_select.set(data["type"])
        self.color_main.insert(0, data["main_color"])
        self.color_secondary.insert(0, data["secondary_color"])
        self.style_select.set(data["style"])
        self.photo_path = data["image_path"]

    def save_cloth(self):
        wardrobe[self.index] = {
            "name": self.name_entry.get(),
            "type": self.type_select.get(),
            "main_color": self.color_main.get(),
            "secondary_color": self.color_secondary.get(),
            "style": self.style_select.get(),
            "image_path": self.photo_path
        }
        save_wardrobe(wardrobe)
        messagebox.showinfo("Updated", "Cloth updated successfully.")
        self.destroy()

if __name__ == "__main__":
    app = OutfitApp()
    app.mainloop()