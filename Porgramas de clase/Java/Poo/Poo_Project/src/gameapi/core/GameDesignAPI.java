package gameapi.core;

/**
 * API para desarrollo de videojuegos con una perspectiva de Top-Down View.
 */
public class GameDesignAPI {
    // Atributos del API
    private String name;
    private String description;
    private String author;
    private String version;
    private String date;

    // Atributos del videojuego
    private String gameName;
    private String gameDescription;
    private String gameAuthor;
    private String gameVersion;
    private String gameDate;
    private String gameType;
    private String gameGenre;
    private String gamePlatform;
    private String gameEngine;
    private String gameMode;
    private String gameControls;
    private String gameInstructions;
    private String gameCredits;
    private String gameLicense;

    // Constructor
    public GameDesignAPI(String name, String description, String author, String version, String date,
                         String gameName, String gameDescription, String gameAuthor, String gameVersion, String gameDate,
                         String gameType, String gameGenre, String gamePlatform, String gameEngine, String gameMode,
                         String gameControls, String gameInstructions, String gameCredits, String gameLicense) {
        this.name = name;
        this.description = description;
        this.author = author;
        this.version = version;
        this.date = date;
        this.gameName = gameName;
        this.gameDescription = gameDescription;
        this.gameAuthor = gameAuthor;
        this.gameVersion = gameVersion;
        this.gameDate = gameDate;
        this.gameType = gameType;
        this.gameGenre = gameGenre;
        this.gamePlatform = gamePlatform;
        this.gameEngine = gameEngine;
        this.gameMode = gameMode;
        this.gameControls = gameControls;
        this.gameInstructions = gameInstructions;
        this.gameCredits = gameCredits;
        this.gameLicense = gameLicense;
    }

    // Getters y Setters
    public String getName() { return name; }
    public void setName(String name) { this.name = name; }

    public String getDescription() { return description; }
    public void setDescription(String description) { this.description = description; }

    public String getAuthor() { return author; }
    public void setAuthor(String author) { this.author = author; }

    public String getVersion() { return version; }
    public void setVersion(String version) { this.version = version; }

    public String getDate() { return date; }
    public void setDate(String date) { this.date = date; }

    public String getGameName() { return gameName; }
    public void setGameName(String gameName) { this.gameName = gameName; }

    public String getGameDescription() { return gameDescription; }
    public void setGameDescription(String gameDescription) { this.gameDescription = gameDescription; }

    public String getGameAuthor() { return gameAuthor; }
    public void setGameAuthor(String gameAuthor) { this.gameAuthor = gameAuthor; }

    public String getGameVersion() { return gameVersion; }
    public void setGameVersion(String gameVersion) { this.gameVersion = gameVersion; }

    public String getGameDate() { return gameDate; }
    public void setGameDate(String gameDate) { this.gameDate = gameDate; }

    public String getGameType() { return gameType; }
    public void setGameType(String gameType) { this.gameType = gameType; }

    public String getGameGenre() { return gameGenre; }
    public void setGameGenre(String gameGenre) { this.gameGenre = gameGenre; }

    public String getGamePlatform() { return gamePlatform; }
    public void setGamePlatform(String gamePlatform) { this.gamePlatform = gamePlatform; }

    public String getGameEngine() { return gameEngine; }
    public void setGameEngine(String gameEngine) { this.gameEngine = gameEngine; }

    public String getGameMode() { return gameMode; }
    public void setGameMode(String gameMode) { this.gameMode = gameMode; }

    public String getGameControls() { return gameControls; }
    public void setGameControls(String gameControls) { this.gameControls = gameControls; }

    public String getGameInstructions() { return gameInstructions; }
    public void setGameInstructions(String gameInstructions) { this.gameInstructions = gameInstructions; }

    public String getGameCredits() { return gameCredits; }
    public void setGameCredits(String gameCredits) { this.gameCredits = gameCredits; }

    public String getGameLicense() { return gameLicense; }
    public void setGameLicense(String gameLicense) { this.gameLicense = gameLicense; }

    
    
}
