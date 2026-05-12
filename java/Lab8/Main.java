import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;
import java.util.Scanner;

public class Main 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter first file name: ");
        String firstFile = scanner.nextLine();

        System.out.print("Enter second file name: ");
        String secondFile = scanner.nextLine();

        System.out.print("Enter output file name: ");
        String outputFile = scanner.nextLine();

        try 
        {
            mergeFiles(firstFile, secondFile, outputFile);
            System.out.println("Files merged successfully into " + outputFile);
        } 
        catch (IOException e) 
        {
            System.out.println("Error while merging files: " + e.getMessage());
        }

        scanner.close();
    }

    private static void mergeFiles(String firstFile, String secondFile, String outputFile) throws IOException {
        try (Writer writer = new FileWriter(outputFile)) 
        {
            copyFile(firstFile, writer);
            writer.write(System.lineSeparator());
            copyFile(secondFile, writer);
        }
    }

    private static void copyFile(String fileName, Writer writer) throws IOException {
        try (Reader reader = new FileReader(fileName)) 
        {
            int character;

            while ((character = reader.read()) != -1) 
            {
                writer.write(character);
            }
        }
    }
}
