package Ch7;

public class TVCR extends Tv{
    VCR vcr = new VCR();

    void play() {
        vcr.play();
    }
    void stop() {
        vcr.stop();
    }
    void rew() {
        vcr.rew();
    }
    void ff() {
        vcr.ff();
    }

    public static void main(String[] args) {

    }
}
class VCR {
    boolean power;
    int counter = 0;
    void power() { power = !power; }
    void play() {
        System.out.println("play");
    }
    void stop() {
        System.out.println("stop");
    }
    void rew() {
        System.out.println("rew");
    }
    void ff() {
        System.out.println("ff");
    }
}
