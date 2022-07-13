import React from 'react';
import { useState } from 'react';

import "./items-style.css";

const SwitchItem = ({ itemName, itemVal, id }) => {
    const [checked, setCheked] = useState(itemVal === "true" ? true : false);

    const revertCheckbox = () => {
        fetch('/update/switch', {
            method: 'PUT',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({
                id: id,
                value: (!checked).toString()
            })
        })
            .then(result => {if(result.ok) setCheked(old => !old)})
            .catch(err => {console.log('Failed to send switch data')})
    }

    return(
        <div className='itemUsual'>
            {itemName} <input type="checkbox" checked={ checked } onChange={revertCheckbox} />
        </div>
    )
}

export default SwitchItem;