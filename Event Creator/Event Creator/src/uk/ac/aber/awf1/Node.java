/*
 * Node Class
 * 
 * This class represnts a node on the course
 * 
 */
package uk.ac.aber.awf1;

/**
 *
 * @author fewstera
 */
class Node {
    
    private int id;
    private String type;
    
    public Node(int id, String type){
        this.id = id;
        this.type = type;
    }
    
    public int getId() {
        return id;
    }

    public String getType() {
        return type;
    }
    
}
