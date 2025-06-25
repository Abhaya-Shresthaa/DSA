int userInput;
    int enqueueInt;
    int choosing;
    while (true)
    {
        cout << "Enter 1 for enqueue: "<< endl;
        cout << "Enter 2 for dequeue: "<< endl;
        cout << "Enter 3 for display: "<< endl;
        cout << "Enter 4 for exit: " << endl;
        cin >> userInput;

        switch(userInput){
            case 1:
                cout<< "Enter 1 for add front: "<< endl;
                cout<< "Enter 2 for add rear: "<< endl;
                cin >> choosing;
                cout << "Enter a integer to enqueue: ";
                cin >> enqueueInt;
                switch (choosing)
                {
                    case 1:
                        dq.addFront(enqueueInt);
                        break;
                    case 2:
                        dq.addRear(enqueueInt);
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                cout<< "Enter 1 for delete front: "<< endl;
                cout<< "Enter 2 for delete rear: "<< endl;
                cin >> choosing;
                switch (choosing)
                {
                    case 1:
                        dq.deleteFront();
                        break;
                    case 2:
                        dq.deleteRear();
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                dq.display();
                break;
            case 4:
                return 0;
            default:
                cout<< "Invalid Choice: ";

        }
    }
    