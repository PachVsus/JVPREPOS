package gameapi.save;

import com.fasterxml.jackson.databind.ObjectMapper;
import java.io.File;
import java.io.IOException;

public class SaveManager {
    public static void saveGame(Object gameData, String filepath) {
        ObjectMapper objectMapper = new ObjectMapper();
        try {
            objectMapper.writeValue(new File(filepath), gameData);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
