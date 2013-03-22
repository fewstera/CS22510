/*
 * Track class
 * 
 * This model represents a Track on a course
 * 
 */
package uk.ac.aber.awf1;

/**
 *
 * @author fewstera
 */
class Track {
    private Node to, from;
    
    Track(Node from, Node to){
        this.from = from;
        this.to = to;
    }

    public Node getTo() {
        return to;
    }

    public Node getFrom() {
        return from;
    }
    
    
    
}
