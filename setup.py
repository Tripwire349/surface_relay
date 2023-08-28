import os
from glob import glob
from setuptools import setup

package_name = 'surface_relay'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='blackwell',
    maintainer_email='blackwell@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        	'sensor_amperage = surface_relay.sensor_amperage:main',
        	'sensor_voltage = surface_relay.sensor_voltage:main',
        	'sensor_temperature = surface_relay.sensor_temperature:main',
        	'sensor_health_summary = surface_relay.sensor_health_summary:main',
        	'sensor_package = surface_relay.sensor_package_temperature_voltage_amperage:main'
        ],
    },
)
