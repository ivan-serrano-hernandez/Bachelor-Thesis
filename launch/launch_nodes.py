from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='main',
            namespace='ods1',
            executable='main_subscriber',
            name='ods'
        ),
        Node(
            package='main',
            namespace='ods2',
            executable='trail_subscriber',
            name='sim'
        ),
        Node(
            package='main',
            namespace='ods3',
            executable='reviewer',
            name='sim'
        ),
        Node(
            package='main',
            namespace='ods4',
            executable='publisher',
            name='sim'
        )

    ])