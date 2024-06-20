from launch import LaunchDescription
from launch_ros.actions import Node

import os

current_directory = os.getcwd()
print("Current directory:", current_directory)

def generate_launch_description():
    
    ld = LaunchDescription()

    publisher = Node(
        package='main',
        executable='publisher'
    )

    instance1 = Node(
        package='main',
        executable='main_subscriber',
        output='screen',
        emulate_tty=True,
        parameters= [
            {'half': False}, 
            {'silent': True}, 
            {'image_size': 320}
        ]
    )

    instance2 = Node(
        package='main',
        executable='trail_subscriber',
        output='screen',
        emulate_tty=True,
        parameters= [
            {'half': True}, 
            {'silent': True}, 
            {'image_size': 320}
        ]
    )

    instance3 = Node(
        package='main',
        executable='tiebreaker',
        output='screen',
        emulate_tty=True,
        parameters= [
            {'half': False}, 
            {'silent': True}, 
            {'image_size': 320}
        ]
    )

    reviewer = Node(
        package='main',
        executable='reviewer'
    )

    
    ld.add_action(instance1)
    ld.add_action(instance2)
    ld.add_action(instance3)
    ld.add_action(reviewer)
    ld.add_action(publisher)

    return ld


    

    


    
    
