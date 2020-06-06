package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    static Set<String> wordsOfLength = new HashSet<>();

    public static void main(String[] args) throws FileNotFoundException {
        char[] alphabet = {
                'а', 'б', 'в', 'г', 'д',
                'е', 'ж', 'з', 'и', 'й',
                'к', 'л', 'м', 'н', 'о',
                'п', 'р', 'с', 'т', 'у',
                'ф', 'х', 'ц', 'ч', 'ш',
                'щ', 'ъ', 'ы', 'ь', 'э',
                'ю', 'я'
        };
        int[] numberOfchar = {10, 3, 5, 3, 5,
                9, 2, 2, 8, 4,
                6, 4, 5, 8, 10,
                6, 6, 6, 5, 3,
                1, 2, 1, 2, 1,
                1, 1, 2, 2, 1,
                1, 3, 3};
        int[] costs = {1, 3, 2, 3, 2,
                1, 5, 5, 1, 2,
                2, 2, 2, 1, 1,
                2, 2, 2, 2, 3,
                10, 5, 10, 5, 10,
                10, 10, 5, 5, 10,
                10, 3, 0};
        ArrayList<Pair<Integer, Integer>> numberAndCosts = new ArrayList<>();
        for (int i = 0; i < numberOfchar.length; i++) {
            numberAndCosts.add(new Pair<>(numberOfchar[i], costs[i]));
        }
        Scanner scanner = new Scanner(new File("src/vocabulary.txt"));
        Set<String> vocabulary = new HashSet<>();
        while (scanner.hasNext()) {
            String line = scanner.nextLine();
            if (line.length() < 9)
                vocabulary.add(line);
        }

        char[] chosen = new char[8];
        for (int i = 0; i < 8; i++) {
            Random random = new Random();
            int rand = random.nextInt(32);
            Pair<Integer, Integer> numAndCos = numberAndCosts.get(rand);
            if (numAndCos.first > 0) {
                chosen[i] = alphabet[rand];
                numAndCos.setFirst(numAndCos.first - 1);
            }
        }
        Arrays.sort(chosen);
        for (int i = 0; i < 8; i++) {
            System.out.print(chosen[i] + " ");
        }
        System.out.println();
        String answer = null;
        for (int i = 8; i >= 1; i--) {

            wordsOfLength = new HashSet<>();
            generateWordsOfLength(chosen, i, new char[i], 0);

            Iterator<String> iterator = wordsOfLength.iterator();
            while (iterator.hasNext()){
                String word = iterator.next();
                if (vocabulary.contains(word)){
                    answer = word;
                    break;
                }
            }
            if (answer != null)
                break;
        }
        System.out.println(answer);
    }

    private static void generateWordsOfLength(char[] alphabet, int length, char[] build, int pos) {
        if (pos == length) {
            String word = new String(build);
            wordsOfLength.add(word);
            return;
        }
        for (int i = 0; i < alphabet.length; i++) {
            build[pos] = alphabet[i];
            generateWordsOfLength(alphabet, length, build, pos + 1);
        }
    }

}
