class LikeButton extends Components {
    state = { likes : 0 }
    
    render() {
        return <button>{this.state.likes}</button>
    }
}

function LikeButton(props) {
    const [likes, setLikes] = useState(0);
    return <button>{likes}</button>;
}