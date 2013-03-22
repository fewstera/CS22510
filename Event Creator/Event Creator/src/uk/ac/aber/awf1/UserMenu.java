/*
 * User Menu Class
 * 
 * This class is responsible for handling the users navigation through the system
 * 
 */
package uk.ac.aber.awf1;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 *
 * @author fewstera
 */
class UserMenu {
    
    private ArrayList<Node> nodes = new ArrayList<Node>();
    private LinkedList<Event> events = new LinkedList<Event>();

    public UserMenu(){
        System.out.println("Welcome to the event creation system.");    
        loadNodesFile();
        topLevelMenu();
    }
    
    private void loadNodesFile(){
        System.out.print("\n\nPlease enter the location of the nodes file: "); 
        String nodesFile = "/Users/fewstera/Documents/CS22510/data/extended/nodes.txt";
        System.out.println(nodesFile + "\n");
        try{
            BufferedReader br = new BufferedReader(new FileReader(nodesFile));
            String line;
            while((line = br.readLine()) != null) {
                String[] stringParts = line.split(" ");
                nodes.add(new Node(Integer.parseInt(stringParts[0]), stringParts[1]));
            }
            System.out.println("\n\nLoaded Successfully!"); 
        } catch (FileNotFoundException ex) {
            System.out.print("\n\nThe file you entered was not found please try again."); 
            loadNodesFile();
        } catch (IOException ex) {
            System.out.println("\n\nError reading file exiting."); 
            System.exit(0);
        }
        
    }

    private void topLevelMenu() {
        System.out.println("\n\nMain Menu\n"
                + "=============================================\n"
                + "Please choose from the following options\n"
                + "1. Create a new event\n"
                + "2. Add entrants and courses to an event\n"
                + "3. Remove an event\n"
                + "4. Generate files for events\n"
                + "5. Exit"
                + "");

        int selection;

        try { //Attempt to receive keyboard input from user
            Scanner in = new Scanner(System.in);
            selection = in.nextInt();
        } catch (InputMismatchException IO) {
            selection = 0; //Invalid user input so set selection to 0
        }
        
        //Switch case to determine the users selection, and call the appropiate method.
        switch (selection) {
            case 1:
                createNewEvent();
                break;
            case 2:
                selectEventToModify();
                topLevelMenu();
                break;
            case 3:
                removeEvent();
                topLevelMenu();
                break;
            case 5:
                break;
            default:
                System.out.println("\n\nERROR: Unexpected input, please enter only the number of your selection. Please try again");
                topLevelMenu(); //Unexpected output, try again

        }
        
    }

    private void createNewEvent() {
        String eventName, eventDate, timeString = "";
        
        System.out.print("\n\nCreate new event\n"
                + "=============================================\n"
                + "Enter the event name: ");
        
        Scanner in = new Scanner(System.in);
        eventName = in.next();
        
        System.out.print("Enter the event date:  ");
        eventDate = in.next();
        
        boolean correctTime = false;
        while(!correctTime){
            System.out.print("Enter the time of the event (HH:MM):  ");
            timeString = in.next();
            Pattern pattern = Pattern.compile("([01][0-9]|2[0-3]):[0-5][0-9]");
            Matcher matcher = pattern.matcher(timeString);
            if(matcher.matches()){
                correctTime = true;
            }else{
                System.out.print("\n\nError incorrect time, try again\n\n");
            }
        }
        events.add(new Event(eventName, eventDate, timeString));
        System.out.print("\n\nEvent created successfully!");
        topLevelMenu();

    }

    private void removeEvent() {
        System.out.println("\n\nRemove an event\n"
                + "=============================================\n"
                + "Which event would you like to delete?");
        int count = 0;
        for (Event event : events) {
            count++;
            System.out.println(count + ". " + event.getName());
        }
        System.out.println(++count + ". Cancel");
        System.out.print("\nEnter the value of your choice: ");
        int selection;
        try { //Attempt to receive keyboard input from user
            Scanner in = new Scanner(System.in);
            selection = in.nextInt();
        } catch (InputMismatchException IO) {
            System.out.print("\n\nInvalid input. Returning to main menu");
            selection = count; //Invalid user input so set selection to count
        }
        if((selection>0)&&(selection<count)){
            events.remove(selection-1);
            System.out.print("\n\nEvent removed.");
        }
    }

    private void selectEventToModify() {
        System.out.println("\n\nSelect an event\n"
                + "=============================================\n"
                + "Which event would you like to modify?");
        int count = 0;
        for (Event event : events) {
            count++;
            System.out.println(count + ". " + event.getName());
        }
        System.out.println(++count + ". Cancel");
        System.out.print("\nEnter the value of your choice: ");
        int selection;
        try { //Attempt to receive keyboard input from user
            Scanner in = new Scanner(System.in);
            selection = in.nextInt();
        } catch (InputMismatchException IO) {
            System.out.print("\n\nInvalid input. Returning to main menu");
            selection = count; //Invalid user input so set selection to count
        }
        if((selection>0)&&(selection<count)){
            events.get(selection-1).listOptions();
        }   
    }

}
