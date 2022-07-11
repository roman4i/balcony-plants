import React from 'react';

const UpdateButton = ({setDoUpdate}) => {
    const toClick = () => {}
    return(
        <button onClick={() => setDoUpdate(true)} >Upd</button>
    );
}

export default UpdateButton;
