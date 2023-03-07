import java.util.Scanner;

class Hello
{

	private String name;

	public Hello(String name)
	{
		this.name = name;
	}

	int	print_hello()
	{
		System.out.println(name);
		return (0);
	}
}

public class	main
{
	public static void	main(String arg[])
	{
		Scanner s = new Scanner(System.in);

		String name = s.nextLine();
		Hello h = new Hello(name);
		h.print_hello();
	}
}
