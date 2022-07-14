{
  const x = 1;
  {
    const y = 2;
    console.log(x);
  }
  console.log(x);
  // y not defined console.log(y);
}

const text = 'global'; // Global Variable, Global Scope
{
  const text = 'inside block1'; // Local Variable, Local Scope
  {
    // const text = 'inside block2';
    console.log(text);
    {
      const text = 'ininside block2';
      {
        console.log(text);
      }
    }
  }
}
console.log(text);
