/*
 * Event class
 * 
 * Responsible for handling all actions on an event
 * 
 */
package uk.ac.aber.awf1;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.Scanner;

/**
 *
 * @author fewstera
 */
class Event {
    
    private String name, date, timeString;
    private LinkedList<Course> courses = new LinkedList<Course>();
    private LinkedList<Entrant> entrants = new LinkedList<Entrant>();
    private UserMenu userMenu;
    
    Event(UserMenu userMenu, String eventName, 
            String eventDate, String eventTimeString){
        this.userMenu = userMenu;
        this.name = eventName;
        this.date = eventDate;
        this.timeString = eventTimeString;
    }

    public String getName() {
        return name;
    }

    public String getDate() {
        return date;
    }

    public String getTimeString() {
        return timeString;
    }

    public void listOptions() {
        System.out.print("\n\n\n\n\nModify " + getName() + "\n"
                + "=============================================\n"
                + "What would you like to do?\n"
                + "1. Add a new course\n"
                + "2. Add or remove nodes to or from a course\n"
                + "3. Remove a course\n"
                + "4. Add an entrant\n"
                + "5. Remove an entrant\n"
                + "6. Return to main menu\n\n"
                + "Enter your selection: ");
        int selection;

        try { //Attempt to receive keyboard input from user
            Scanner in = new Scanner(System.in);
            selection = in.nextInt();
        } catch (InputMismatchException IO) {
            selection = 0; //Invalid user input so set selection to 0
        }
        
        //Switch case to determine the users 
        //selection, and call the appropiate method.
        switch (selection) {
            case 1:
                addNewCourse();
                listOptions();
                break;
            case 2:
                modifyCourse();
                listOptions();
                break;
            case 3:
                removeCourse();
                listOptions();
                break;
            case 4:
                addEntrant();
                listOptions();
                break;
            case 5:
                removeEntrant();
                listOptions(); 
                break;
            case 6:
                break;
            default:
                System.out.println("\n\n\nERROR: Unexpected input, please enter"
                        + " only the number of your selection. Please try again");
                listOptions(); //Unexpected output, try again
                break;

        }
    }

    private void addNewCourse() {
        System.out.print("\n\nAdd new course\n"
                + "=============================================\n"
                + "Note: Prefixs must be a single character\n\n"
                + "Please enter a prefix for your course: ");
        Scanner in = new Scanner(System.in);
        char letter = in.next().toUpperCase().charAt(0); 
        if(Character.isLetter(letter)){
            if(getCourse(letter)==null){
                courses.add(new Course(userMenu, letter));
            }else{
                System.out.print("\n\nA course already exists with "
                        + ""
                        + "this prefix. try again");
                addNewCourse();  
            }
        }else{
             System.out.print("\n\nInvalid prefix, try again.");
             addNewCourse();
        }
        
    }

    private Course getCourse(char letter) {
        for(Course course : courses){
            if(course.getId()==letter){
                return course;
            }
        }
        return null;
    }

    private void removeCourse() {
        System.out.print("\n\nRemove a course\n"
                + "=============================================\n"
                + "Which course would you like to remove?\n");
        int count = 0;
        for (Course course : courses) {
            count++;
            System.out.println(count + ". " + course.getId());
        }
        System.out.println(++count + ". Cancel");
        System.out.print("\nEnter the value of your choice: ");
        int selection;
        try { //Attempt to receive keyboard input from user
            Scanner in = new Scanner(System.in);
            selection = in.nextInt();
        } catch (InputMismatchException IO) {
            System.out.print("\n\nInvalid input. Returning to modify page.");
            selection = count; //Invalid user input so set selection to count
        }
        if((selection>0)&&(selection<count)){
            courses.remove(selection-1);
            System.out.print("\n\nCourse removed.");
        }
    }

    private void addEntrant() {
        if(courses.size()==0){
            System.out.print("\n\nYou must have atleast one course "
                    + "before you can add entrants");
        }else{
            String entrantName;
            Course entrantCourse = null;
            System.out.print("\n\nAdd a new entrant to " + this.getName() + "\n"
                    + "=============================================\n"
                    + "Enter the entrants name: ");

            Scanner in = new Scanner(System.in);
            entrantName = in.nextLine();

            boolean courseSelected = false;
            while(!courseSelected){
                System.out.println("Which course is " + entrantName + " on?");
                int count = 0;
                for (Course course : courses) {
                    count++;
                    System.out.println(count + ". " + course.getId());
                }
                System.out.print("\nEnter the value of your choice: ");
                int selection = 0;
                try { //Attempt to receive keyboard input from user
                    selection = in.nextInt();
                    if((selection>0)&&(selection<=count)){
                        entrantCourse = courses.get(selection-1);
                        courseSelected = true;
                    }

                } catch (InputMismatchException IO) {
                    System.out.print("\n\nInvalid input. Try again");
                }
            }
            entrants.add(new Entrant(entrantCourse, entrantName));
            System.out.print("\n\nAdded " + entrantName + "to " + this.getName());
        }
    }

    private void removeEntrant() {
        System.out.print("\n\nRemove an entrant\n"
                + "=============================================\n"
                + "Which entrant would you like to remove?\n");
        int count = 0;
        for (Entrant entrant : entrants) {
            count++;
            System.out.println(count + ". " + entrant.getName());
        }
        System.out.println(++count + ". Cancel");
        System.out.print("\nEnter the value of your choice: ");
        int selection;
        try { //Attempt to receive keyboard input from user
            Scanner in = new Scanner(System.in);
            selection = in.nextInt();
        } catch (InputMismatchException IO) {
            System.out.print("\n\nInvalid input. Returning to modify event page.");
            selection = count; //Invalid user input so set selection to count
        }
        if((selection>0)&&(selection<count)){
            entrants.remove(selection-1);
            System.out.print("\n\nEntrant removed.");
        }    
    }

    private void modifyCourse() {
        System.out.println("\n\nModify a course\n"
                + "=============================================\n"
                + "Which course would you like to modify?");
        int count = 0;
        for (Course course : courses) {
            count++;
            System.out.println(count + ". " + course.getId());
        }
        System.out.println(++count + ". Cancel");
        System.out.print("\nEnter the value of your choice: ");
        int selection;
        try { //Attempt to receive keyboard input from user
            Scanner in = new Scanner(System.in);
            selection = in.nextInt();
        } catch (InputMismatchException IO) {
            System.out.print("\n\nInvalid input. Returning to modify event page");
            selection = count; //Invalid user input so set selection to count
        }
        if((selection>0)&&(selection<count)){
            courses.get(selection-1).listOptions();
        }
    }
    
    //Gnerate the text for an event file
    public String generateEventFile(){
        return getName() + "\n" + getDate() + "\n" + getTimeString();
    }
    
    //Generates the text for a course file
    public String generateCoursesFile(){
        String returnString = "";
        for(Course course: courses){
            returnString = returnString + course.toFormatedString() + "\n";
        }
        return returnString;
    }
    
    //Generates the text for an entrants file
    public String generateEntrantsFile(){
        String returnString = "";
        int count = 1;
        for(Entrant entrant: entrants){
            returnString = returnString + count + " "
                    + "" + entrant.toFormatedString() + "\n";
            count++;
        }
        return returnString;
    }
    
}
