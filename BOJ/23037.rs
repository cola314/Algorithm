use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let result = solve(&input.trim());
    println!("{}", result);
}

fn solve(input: &str) -> i32 {
    input.chars()
        .map(|x| x.to_string().parse::<i32>().unwrap())
        .map(|x| x.pow(5))
        .sum()
}

#[cfg(test)]
mod tests {
    use crate::solve;

    #[test]
    fn example1() {
        assert_eq!(solve("12345"), 4425);
    }

    #[test]
    fn example2() {
        assert_eq!(solve("54748"), 54748);
    }

    #[test]
    fn example3() {
        assert_eq!(solve("92727"), 92727);
    }

    #[test]
    fn example4() {
        assert_eq!(solve("93084"), 93084);
    }
}
