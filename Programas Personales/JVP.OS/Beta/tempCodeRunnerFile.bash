# Function to display the main menu
show_main_menu() {
    menu_choice=$(dialog --clear --title "Main Menu" \
        --menu "Choose an option:" 15 50 4 \
        1 "Option 1" \
        2 "Option 2" \
        3 "Option 3" \
        4 "Exit" \
        --output-fd 1)

    if [ $? -ne 0 ]; then
        exit 0  # User pressed Esc or Ctrl+C
    fi

    case $menu_choice in
        1) show_option "Option 1" ;;
        2) show_option "Option 2" ;;
        3) show_option "Option 3" ;;
        4) exit 0 ;;
    esac
}

# Function to display a selected option
show_option() {
    dialog --clear --title "$1" --msgbox "You selected $1" 10 30
    show_main_menu
}

# Ensure dialog is installed
if ! command -v dialog &> /dev/null; then
    echo "Error: 'dialog' is not installed. Please install it."
    exit 1
fi

# Start the script
show_main_menu
