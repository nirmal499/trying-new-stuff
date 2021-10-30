package mod9.shared;

/* The alarm system will have three different kinds of sensors – 
    a Gateway sensor, a Movement sensor, and a Fire sensor. They will all have the same basic qualities but
    may differ in certain aspects. Create the Base sensor interface and let it have two
    getter/setter pairs 
*/
public interface Sensor {
    int batteryHealth();

    void batteryHealth(int health);

    boolean triggered();

    void triggered(boolean state);
}
