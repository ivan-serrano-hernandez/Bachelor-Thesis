from setuptools import find_packages, setup

package_name = 'main'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='iserran1',
    maintainer_email='i.serranoher@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'publisher = pub.publisher:main',  
            'main_subscriber = main_subscriber.instance1:main',  
            'trail_subscriber = trail_subscriber.instance2:main',
            'reviewer = reviewer.reviewer:main',
        ],
    },
)
