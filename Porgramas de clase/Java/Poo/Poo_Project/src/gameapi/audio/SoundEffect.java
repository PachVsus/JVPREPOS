package gameapi.audio;

import java.io.File;
import java.io.IOException;
import javax.sound.sampled.*;

public class SoundEffect {
    public static void playSound(String filepath) {
        try {
            File soundFile = new File(filepath);
            AudioInputStream audioStream = AudioSystem.getAudioInputStream(soundFile);
            Clip clip = AudioSystem.getClip();
            clip.open(audioStream);
            clip.start();
        } catch (UnsupportedAudioFileException | IOException | LineUnavailableException e) {
            e.printStackTrace();
        }
    }
}
