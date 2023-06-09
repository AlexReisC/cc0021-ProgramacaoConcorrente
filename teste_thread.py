import threading
from random import randint
import time

def tarefa1(min,max):
    time.sleep(randint(0,10))
    print(threading.current_thread().name)
    print(randint(min,max))


def main():
    thread1 = threading.Thread(target=tarefa1,args=(0,10),name='TAREFA 1')
    thread2 = threading.Thread(target=tarefa1,args=(10,100),name='TAREFA 2')
    thread3 = threading.Thread(target=tarefa1,args=(100,1000),name='TAREFA 3')
    thread4 = threading.Thread(target=tarefa1,args=(1000,10000),name='TAREFA 4')
    
    thread1.start()
    thread2.start()
    thread3.start()
    thread4.start()
    
    thread1.join()
    thread2.join()
    thread3.join()
    thread4.join()
    print("CONTINUANDO...")

if __name__ == "__main__":
    main()