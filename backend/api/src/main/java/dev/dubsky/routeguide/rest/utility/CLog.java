package dev.dubsky.routeguide.rest.utility;

/**
 * Class for colored console output
 */
public class CLog {

    public static boolean DEBUG = true;
    private static final String RESET = "\033[0m";
    private static final String GREEN = "\033[92m";
    private static final String YELLOW = "\033[93m";
    private static final String RED = "\033[91m";
    
    /**
     * Print text with color
     * @param colorCode 0 - green, 1 - yellow, 2 - red, other - reset
     * @param text text to print
     */
    public static void out(int colorCode, String text) {
        if (!DEBUG) {
            return;
        }
        String color;
        switch (colorCode) {
            case 0:
                color = GREEN;
                break;
            case 1:
                color = YELLOW;
                break;
            case 2:
                color = RED;
                break;
            default:
                color = RESET;
        }
        System.out.println(color + text + RESET);
    }
}