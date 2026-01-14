fn insertion_sort(elements_list: &mut [i32]) {
    let n = elements_list.len();
    for index in 1..n {
        let current_value = elements_list[index];
        let mut current_index = index;
        while current_index > 0 && current_value < elements_list[current_index - 1] {
            elements_list[current_index] = elements_list[current_index - 1];
            current_index -= 1;
            println!("{:?}", elements_list);
        }
        elements_list[current_index] = current_value;
    }
}
fn main() {
    let mut elements = [100, 80, 30, 20, 2, 1, 0];

    insertion_sort(&mut elements[0..]);
}
