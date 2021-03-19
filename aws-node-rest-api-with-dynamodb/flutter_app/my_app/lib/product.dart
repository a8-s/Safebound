class Product {
  final String name;
  final String description;
  final String price;
  final String imageURL;

  const Product({
    this.name,
    this.description,
    this.price,
    this.imageURL,
  });

  factory Product.fromJson(Map<String, dynamic> json) {
    return Product(
      name: json['name'].toString(),
      description: json['description'].toString(),
      price: json['price'].toString(),
      imageURL: json['imageURL'].toString(),
    );
  }
}