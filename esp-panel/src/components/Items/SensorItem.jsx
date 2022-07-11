import React, { useState, useEffect } from 'react';
import UpdateButton from '../Buttons/UpdateButton';

import "./items-style.css";

const SensorItem = ({itemName, itemVal, id}) => {
    const [doUpdate, setDoUpdate] = useState(false);
    const [currentVal, setCurrentVal] = useState(itemVal);

    useEffect(() => {
        if(doUpdate === true) {
            setCurrentVal('---');
            fetch('/getSensor/' + id)
                .then(resp => resp.json())
                .then(result => setCurrentVal(result.value));
            setDoUpdate(false);
        }
    }, [doUpdate])

    return(
        <div className='itemUsual'>
            {itemName} {currentVal} <UpdateButton setDoUpdate={setDoUpdate} />
        </div>
    )
}

export default SensorItem;