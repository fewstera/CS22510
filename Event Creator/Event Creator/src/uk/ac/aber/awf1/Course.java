/*
 * Course class
 * 
 * This class represents a course
 * 
 */
package uk.ac.aber.awf1;

/**
 *
 * @author fewstera
 */
class Course {
    
    char id;
    
    Course(char id){
        this.id = id;
    }
    
    public char getId(){
        return this.id;
    }
    
}
