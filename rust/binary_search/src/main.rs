fn loop_binary_search(array: &[i32], value: i32) -> Option<usize> {
    let mut start: usize = 0;
    let mut end: usize = if array.is_empty() { 0 } else { array.len() };
    while start < end {
        let mid = start + (end - start) / 2;
        if array[mid] == value {
            return Some(mid);
        } else if value > array[mid] {
            start = mid + 1;
        } else if value < array[mid] {
            end = mid;
        }
    }
    None
}
fn main() {
    let ordered_array: [i32; 8] = [10, 20, 30, 40, 50, 60, 70, 80];
    match loop_binary_search(&ordered_array[..], 50) {
        Some(index) => println!("The index was found at {}", index),
        None => println!("No value was found "),
    }
}
