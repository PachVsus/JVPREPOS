import requests

# Configuramos las voces del asistente
engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id)

# Variables globales para almacenar la configuración
selected_gender = None
selected_personality = None

# Menu de configuracion inicial
def configMenu():
    global selected_gender
    print("Bienvenido a la configuracion inicial de JVP.AI")
    print("Por favor selecciona el genero de tu asistente:")
    print("1. Masculino")
    print("2. Femenino")
    print("3. Salir")

    while True:
        try:
            option = int(input("Selecciona una opcion: "))
            if option == 1:
                selected_gender = "masculino"
                print("Has seleccionado genero masculino")
                break
            elif option == 2:
                selected_gender = "femenino"
                print("Has seleccionado genero femenino")
                break
            elif option == 3:
                print("Has seleccionado salir")
                exit()
            else:
                print("Opcion no valida, por favor selecciona una opcion valida")
        except ValueError:
            print("Por favor selecciona una opcion valida")

# Menu de personalidad y actitud del asistente
def personalityMenu():
    global selected_personality
    print("Por favor selecciona la personalidad y actitud de tu asistente:")
    print("1. Amable")
    print("2. Neutral")
    print("3. Gymbro")
    print("4. Motociclista")
    print("5. Luchador")
    print("6. Militar")
    print("7. Robot")
    print("8. Niño")
    print("9. Niña")
    print("10. Anciano")
    print("11. Anciana")
    print("12. Alien")
    print("13. Fantasma")
    print("14. Vampiro")
    print("15. Zombie")
    print("16. Bruja")
    print("17. Demonio")
    print("18. Angel")
    print("19. Dios")
    print("20. Diablo")
    print("21. Superheroe")
    print("22. Supervillano")
    print("23. Villano")
    print("24. Heroe")
    print("25. Antiheroe")
    print("26. Boxeador")
    print("27. Ninja")
    print("28. Samurai")
    print("29. Pirata")
    print("30. Vaquero")
    print("31. Vaquera")
    print("32. Policia")
    print("33. Ladron")
    print("34. Hacker")
    print("35. Programador")
    print("36. Ingeniero")
    print("37. Cientifico")
    print("38. Doctor")
    print("39. Enfermero")
    print("40. Paciente")
    print("41. Abogado")
    print("42. Juez")
    print("43. Politico")
    print("44. Rey")
    print("45. Reina")
    print("46. Principe")
    print("47. Princesa")
    print("48. Duque")
    print("49. Duquesa")
    print("50. Conde")
    print("51. Condesa")
    print("52. Marques")
    print("53. Marquesa")
    print("54. Baron")
    print("55. Baronessa")
    print("56. Emperador")
    print("57. Emperatriz")
    print("58. Sacerdote")
    print("59. Monja")
    print("60. Monje")
    print("61. Monarca")
    print("62. Dictador")
    print("63. Tirano")
    print("64. Rehén")
    print("65. Secuestrador")
    print("66. Asesino")
    print("67. Asesina")
    print("68. Asesino en serie")
    
    while True:
        try:
            option = int(input("Selecciona una opcion: "))
            if 1 <= option <= 68:
                selected_personality = option
                print(f"Has seleccionado la personalidad {option}")
                break
            else:
                print("Opcion no valida, por favor selecciona una opcion valida")
        except ValueError:
            print("Por favor selecciona una opcion valida")

# Funcion para dar la bienvenida
def wishMe():
    hour = int(datetime.datetime.now().hour)
    greeting = ""
    if hour >= 0 and hour < 12:
        greeting = "Buenos dias!"
    elif hour >= 12 and hour < 18:
        greeting = "Buenas tardes!"
    else:
        greeting = "Buenas noches!"
    
    print(f"{greeting} Soy JVP.AI con personalidad {selected_personality}, en que puedo ayudarte?")

# Funcion para mejorar la personalidad y actitud del asistente virtual AI basandose de opensource en la web mediante autoaprendizaje IA automatico
def improvePersonality(personality):
    try:
        response = requests.get(f"https://api.example.com/improve_personality?personality={personality}")
        if response.status_code == 200:
            improvement = response.json().get("improvement", "No improvement found")
            with open("personality_improvements.txt", "a") as imp_file:
                imp_file.write(f"Personality: {personality}, Improvement: {improvement}\n")
        else:
            print("Error al obtener mejoras de personalidad")
    except Exception as e:
        print(f"Error al conectar con la API: {e}")

# Funcion principal
if __name__ == "__main__":
    configMenu()
    personalityMenu()
    improvePersonality(selected_personality)
    wishMe()
    while True:
        query = takeCommandManual().lower()
        response = ""
        if 'wikipedia' in query:
            print('Buscando en Wikipedia...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences=2)
            response = f"Segun Wikipedia: {results}"
            print(response)
        elif 'abrir youtube' in query:
            webbrowser.open("youtube.com")
            response = "Abriendo YouTube"
        elif 'abrir google' in query:
            webbrowser.open("google.com")
            response = "Abriendo Google"
        elif 'abrir stackoverflow' in query:
            webbrowser.open("stackoverflow.com")
            response = "Abriendo StackOverflow"
        elif 'hora' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")
            response = f"La hora actual es {strTime}"
            print(response)
        elif 'salir' in query:
            response = "Adios!"
            print(response)
            break
        else:
            response = "No entiendo, por favor repite..."
            print(response)
        
        # Log the interaction for learning
        learnFromInteraction(selected_personality, "neutral", query, response)
