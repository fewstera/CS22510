/*
 * Course class
 * 
 * This class represents a course
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
class Course {
    
    private char id;
    private LinkedList<Node> nodes = new LinkedList<Node>();
    private UserMenu userMenu;
    
    Course(UserMenu userMenu, char id){
        this.userMenu = userMenu;
        this.id = id;
    }
    
    public char getId(){
        return this.id;
    }

    public LinkedList<Node> getNodes() {
        return nodes;
    }
    
    public void listOptions() {
        System.out.print("\n\n\n\n\nModify Course " + getId() + "\n"
                + "=============================================\n"
                + "What would you like to do?\n"
                + "1. Add a new node\n"
                + "2. Remove a node\n"
                + "3. Return to modify event menu\n\n"
                + "Enter your selection: ");
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
                addNode();
                listOptions();
                break;
            case 2:
                removeNode();
                listOptions();
                break;
            case 3:
                break;
            default:
                System.out.println("\n\n\nERROR: Unexpected input, please enter only the number of your selection. Please try again");
                listOptions(); //Unexpected output, try again
                break;

        }
    }

    private void addNode() {
        if(nodes.size()==0){
            System.out.println("\n\nSelect Starting Node\n"
                + "=============================================\n"
                + "Select the start of the course\n");
            int count = 0;
            for (Node node : userMenu.getNodes()) {
                count++;
                System.out.println(count + ". " + node.getId());
            }
            System.out.println(++count + ". Cancel");
            System.out.print("\nEnter the value of your choice: ");
            int selection;
            try { //Attempt to receive keyboard input from user
                Scanner in = new Scanner(System.in);
                selection = in.nextInt();
            } catch (InputMismatchException IO) {
                System.out.print("\n\nInvalid input. Returning to modify course page");
                selection = count; //Invalid user input so set selection to count
            }
            if((selection>0)&&(selection<count)){
                nodes.add(userMenu.getNodes().get(selection-1));
                System.out.print("\n\nAdded new node!");
            }
        }else{
            System.out.println("\n\nAdd an extra node\n"
                + "=============================================\n"
                + "Below is a list of nodes linked to the last node (" + nodes.getLast().getId() + "). \n"
                    + "Select which node you would like to add to the list.\n");
            
            int count = 0;
            ArrayList<Node> availableNodes = availableNodes();
            for (Node node : availableNodes) {
                count++;
                System.out.println(count + ". " + node.getId());
            }
            System.out.println(++count + ". Cancel");
            System.out.print("\nEnter the value of your choice: ");
            int selection;
            try { //Attempt to receive keyboard input from user
                Scanner in = new Scanner(System.in);
                selection = in.nextInt();
            } catch (InputMismatchException IO) {
                System.out.print("\n\nInvalid input. Returning to modify course page");
                selection = count; //Invalid user input so set selection to count
            }
            if((selection>0)&&(selection<count)){
                nodes.add(availableNodes.get(selection-1));
                System.out.print("\n\nAdded new node!");
            }
        }
    }

    private void removeNode() {
        if(nodes.size()==0){
            System.out.print("\n\nThere isn't any nodes to remove");
        }else{
            System.out.print("\n\nRemove a node\n"
                + "=============================================\n"
                + "Please select from the following options\n"
                + "1. Remove first node\n"
                + "2. Remove last node\n"
                + "3. Cancel");
            int selection;
            try { //Attempt to receive keyboard input from user
                Scanner in = new Scanner(System.in);
                selection = in.nextInt();
            } catch (InputMismatchException IO) {
                System.out.print("\n\nInvalid input. Returning to modify course page");
                selection = 3; //Invalid user input so set selection to count
            }
            if(selection==1){
                nodes.removeFirst();
            }else if(selection==2){
                nodes.removeLast();
            }
        }
    }
    
    private ArrayList<Node> availableNodes(){
        ArrayList<Node> returnList = new ArrayList<Node>();
        Node lastNode = nodes.getLast();
        for(Track track : userMenu.getTracks()){
            if(track.getFrom().getId()==lastNode.getId()){
                returnList.add(track.getTo());
            }else if(track.getTo().getId()==lastNode.getId()){
                returnList.add(track.getFrom());
            }
        }
        return returnList;
    }
    
    public String toFormatedString(){
        String returnString = getId() + " " + nodes.size();
        for(Node node: nodes){
            returnString =  returnString + " " + node.getId();
        }
        return returnString;
    }
}
