import React from 'react';
import { useState } from 'react';

import "./items-style.css";

const SliderItem = ({ itemName, itemVal, id }) => {
    const [val, setVal] = useState(itemVal);

    const changeSlider = (event) => {
        setVal(event.target.value);
    }

    const sendRangeData = () => {
        fetch('/update/slider', {
            method: 'PUT',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({
                id: id,
                value: val
            })
        })
            .catch(err => console.log('Failed to send slider value'));
    }

    return(
        <div className='itemUsual'>
            <div>{itemName} {val}</div>
            <input type="range" min={0} max={100} value={val} onChange={changeSlider} onMouseUp={sendRangeData} />
        </div>
    )
}

export default SliderItem;