int func(int i)
{
    return func(i+1);
}

int main()
{
    func(0);

    return 0;
}
