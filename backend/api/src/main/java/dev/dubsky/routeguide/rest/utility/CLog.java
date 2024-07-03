package dev.dubsky.routeguide.rest.utility;

public class CLog {
    private static final String RESET = "\033[0m";
    private static final String GREEN = "\033[92m";
    private static final String YELLOW = "\033[93m";
    private static final String RED = "\033[91m";
    
    public static void out(int colorCode, String text) {
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