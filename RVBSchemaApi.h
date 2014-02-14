#import <Foundation/Foundation.h>
#import "NIKApiInvoker.h"
#import "RVBFieldSchema.h"
#import "RVBFields.h"
#import "RVBResources.h"
#import "RVBTableSchema.h"
#import "RVBSuccess.h"
#import "RVBTables.h"


@interface RVBSchemaApi: NSObject {

@private
    NSOperationQueue *_queue;
    NIKApiInvoker * _api;
}
@property(nonatomic, readonly) NSOperationQueue* queue;
@property(nonatomic, readonly) NIKApiInvoker* api;

-(void) addHeader:(NSString*)value forKey:(NSString*)key;

/**

 getResources() - List resources available for database schema.
 See listed operations for each resource available.
 */
-(void) getResourcesWithCompletionBlock :(void (^)(RVBResources* output, NSError* error))completionBlock;

/**

 createTables() - Create one or more tables.
 Post data should be a single table definition or an array of table definitions.
 @param body Array of table definitions.
 */
-(void) createTablesWithCompletionBlock :(RVBRVBTables**) body 
        completionHandler: (void (^)(RVBResources* output, NSError* error))completionBlock;

/**

 updateTables() - Update one or more tables.
 Post data should be a single table definition or an array of table definitions.
 @param body Array of table definitions.
 */
-(void) updateTablesWithCompletionBlock :(RVBRVBTables**) body 
        completionHandler: (void (^)(RVBResources* output, NSError* error))completionBlock;

/**

 describeTable() - Retrieve table definition for the given table.
 This describes the table, its fields and relations to other tables.
 @param table_name Name of the table to perform operations on.
 */
-(void) describeTableWithCompletionBlock :(RVBNSString**) table_name 
        completionHandler: (void (^)(RVBTableSchema* output, NSError* error))completionBlock;

/**

 createFields() - Create one or more fields in the given table.
 Post data should be an array of field properties for a single record or an array of fields.
 @param table_name Name of the table to perform operations on.
 @param body Array of field definitions.
 */
-(void) createFieldsWithCompletionBlock :(RVBNSString**) table_name 
        body:(RVBRVBFields**) body 
        completionHandler: (void (^)(RVBSuccess* output, NSError* error))completionBlock;

/**

 updateFields() - Update one or more fields in the given table.
 Post data should be an array of field properties for a single record or an array of fields.
 @param table_name Name of the table to perform operations on.
 @param body Array of field definitions.
 */
-(void) updateFieldsWithCompletionBlock :(RVBNSString**) table_name 
        body:(RVBRVBFields**) body 
        completionHandler: (void (^)(RVBSuccess* output, NSError* error))completionBlock;

/**

 deleteTable() - Delete (aka drop) the given table.
 Careful, this drops the database table and all of its contents.
 @param table_name Name of the table to perform operations on.
 */
-(void) deleteTableWithCompletionBlock :(RVBNSString**) table_name 
        completionHandler: (void (^)(RVBSuccess* output, NSError* error))completionBlock;

/**

 describeField() - Retrieve the definition of the given field for the given table.
 This describes the field and its properties.
 @param table_name Name of the table to perform operations on.
 @param field_name Name of the field to perform operations on.
 */
-(void) describeFieldWithCompletionBlock :(RVBNSString**) table_name 
        field_name:(RVBNSString**) field_name 
        completionHandler: (void (^)(RVBFieldSchema* output, NSError* error))completionBlock;

/**

 updateField() - Update one record by identifier.
 Post data should be an array of field properties for the given field.
 @param table_name Name of the table to perform operations on.
 @param field_name Name of the field to perform operations on.
 @param body Array of field properties.
 */
-(void) updateFieldWithCompletionBlock :(RVBNSString**) table_name 
        field_name:(RVBNSString**) field_name 
        body:(RVBRVBFieldSchema**) body 
        completionHandler: (void (^)(RVBSuccess* output, NSError* error))completionBlock;

/**

 deleteField() - Remove the given field from the given table.
 Careful, this drops the database table field/column and all of its contents.
 @param table_name Name of the table to perform operations on.
 @param field_name Name of the field to perform operations on.
 */
-(void) deleteFieldWithCompletionBlock :(RVBNSString**) table_name 
        field_name:(RVBNSString**) field_name 
        completionHandler: (void (^)(RVBSuccess* output, NSError* error))completionBlock;

@end