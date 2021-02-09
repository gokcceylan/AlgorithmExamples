public class SortArrayOfInt {
	public static void main(String[] args) {
		//Sort an array of integers from least to greatest without any API functions
		
		//take the integer array
		int N[] = {1, 2, 6, 99, 7};
		//send it to the method
		int result[] = sorter(N);
		//print it on a loop
		for(int i: result)
			System.out.println(i);
	}
	
	public static int[] sorter(int N[]) {
		int temp = 0;
		//create array with same length
		//sort by bubble sort
		//it's not the most efficient way but it works
		for(int i = 0; i < N.length - 1; i++) {
			for(int j = 0; j < N.length - i - 1; j++) {
				if(N[j] > N[j+1]) {
					//sort
					temp = N[j]; 
                    N[j] = N[j + 1]; 
                    N[j + 1] = temp;
				}
			}
		}
		
		return N;
	}
	
}
