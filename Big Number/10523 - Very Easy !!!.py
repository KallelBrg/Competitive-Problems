def main():
    
    while True:
        try:
            n,a=list(map(int, input().split()))
            s = 0
            for i in range(1,n+1):
                s+=i*pow(a, i)
            
            print(s)
            
            
        except EOFError:
            break
    
if __name__ == "__main__":
    main()
