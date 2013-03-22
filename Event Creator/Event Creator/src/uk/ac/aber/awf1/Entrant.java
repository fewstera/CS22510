/*
 * Entrant class
 * 
 * This class represents an entrant
 * 
 */
package uk.ac.aber.awf1;

/**
 *
 * @author fewstera
 */
class Entrant {
   private Course course;
   private String name;
   
   Entrant(Course course, String name){
       this.course = course;
       this.name = name;
   }

    public Course getCourse() {
        return course;
    }

    public String getName() {
        return name;
    }
   
   
}
