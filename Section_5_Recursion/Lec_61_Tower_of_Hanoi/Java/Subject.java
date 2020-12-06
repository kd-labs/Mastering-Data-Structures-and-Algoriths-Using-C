import java.util.ArrayList;
import java.util.List;

public interface Subject {

    public void registerObserver(Observer follower);
    public void removeObserver(Observer follower);
    public void notifyObservers();

}

interface Observer {
	public void update(String status);
}

class Channel implements Subject {
  
    private List<Observer> observers;
    private String channelName;
    private String status;

    public Channel(String channelName) {
        this.observers = new ArrayList<Observer>();
        this.channelName = channelName;
    }
    public void setStatus(String status) {
        this.status = status;
    }

    public String getStatus() {
        return this.status;
    }

    @Override
    public void registerObserver(Observer follower) {
        this.observers.add(follower);
    }

    @Override
    public void removeObserver(Observer follower) {
        this.observers.remove(follower);
    }

    @Override
    public void notifyObservers() {
        this.observers.forEach(x -> x.update(status));
	
    }
}

class Follower implements Observer {

    private String followerName;

    Follower(String followerName) {
        this.followerName = followerName;
    }

    @Override
    public void update(String status) {
        this.play();
    }

    public void play() {
        // play the video
    }

}
