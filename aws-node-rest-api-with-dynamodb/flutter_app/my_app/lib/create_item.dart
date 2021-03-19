import 'package:my_app/product.dart';
import 'package:http/http.dart' as http;

Future<void> createItem(Product product) async {
  Uri url = Uri.parse("https://6wfudnghd2.execute-api.us-east-1.amazonaws.com/dev/todos");
  return http
      .post(url,
          body: "{" +
              "\"name\": \"${product.name}\", \"description\": \"${product.description}\", \"price\": \"${product.price}\", \"imageURL\": \"${product.imageURL}\" }")
      .then((http.Response response) {
    final int statusCode = response.statusCode;
    if (statusCode == 200) {
      return;
    } else {
      throw new Exception("Error while fetching data ${statusCode}");
    }
  });
}