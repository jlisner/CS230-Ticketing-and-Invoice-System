CS230-Project2-Ticketing-and-Invoice-System

Design Requirements based on Learning Objectives

=================================================================

Make sure that your design include the following concepts:

    encapsulation/abstraction

    inehritance

    Polymorphism

    Linked lists, stacks, queues or vectors and even an implementation of hash tables

    Sorting

    Data manipulation: Edit, add, delete

    Menu driven application

    File I/O

This is a group project where you will coordinate to think out the problem requirements and draft a good design domain strategy that will yield a smooth implementation that covers the above listed academic requirements.

Submit your source code, record files and an individual paper describing the project, its technical challenges and how you accomplished your goals.

Make sure that you list the participants in your project.

The paper will be in APA Style!

You will use citation where needed and must have a reference list.

Each group should be of the same major! (ABET related measurements).

As a group you will coordinate in building the project from a design to implementation. Each member of the group will submit an individual report!

====================================================================

The project: Ticketing and Invoice System

Design an application that allows a technician to issue a service ticket on equipment to be repaired. When the equipment is repaired, the system should issue a customer invoice.

The system will track the progress of the equipment's repair status in terms of:

    Time and date the equipment is entered in the system by a technician

    Repair status (pending, waiting for parts, complete)

    Time spent on repairs and any technician name associated with the repairs (can be more than one)

    List of parts used for the repairs with time and dates of installation

    Time and date the equipment was certified as repaired and signed off by the repair department manager

At the end of the day (Reporting Phase), the repair department manager should be able print invoices for repaired equipment (the ones that were not already invoiced but have been completed on that day).

The manager should be able to print all incomplete repairs and list them based on their status: pending or waiting for parts. (Pending means still in the process of being repaired or not started).

The pending tickets should show time, parts and who worked on the equipment.

The invoice should reflect the labor and parts costs to the customer!

Details:

Equipment belong to customers, both must be tracked.

Repair technicians do not charge the same for their services. Expertise levels should dictate the rate ranging from $100 an hour for general labor and $250 an hour for expert services. Make sure you rank employees so that labor reflect those charges.

Flags: During reporting, make sure that all equipment that are pending or are about to be invoiced that have more than 5 hours of labor are shown. This should identify backlogs or problematic equipment.

All information is stored in files! The program should start where it left off, in other words, data must be persistant. You may want to consider log files to track the operations of the application so that you have a startup file from which to load up to date parameters.

    © 2019 GitHub, Inc.
    Terms
    Privacy
    Security
    Status
    Help

    Contact GitHub
    Pricing
    API
    Training
    Blog
    About

