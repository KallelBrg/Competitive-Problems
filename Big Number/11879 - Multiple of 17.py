def main():
    while True:
        x = int(input())
        if not x: break
        if x%17 == 0: print('1')
        else: print ('0')
if __name__ == "__main__":
    main()
