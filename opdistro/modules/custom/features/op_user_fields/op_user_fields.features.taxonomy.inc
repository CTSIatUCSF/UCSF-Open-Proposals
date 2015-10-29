<?php
/**
 * @file
 * op_user_fields.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function op_user_fields_taxonomy_default_vocabularies() {
  return array(
    'departments' => array(
      'name' => 'Departments',
      'machine_name' => 'departments',
      'description' => 'List of department names from UCSF Profiles (Feb 2012)',
      'hierarchy' => 1,
      'module' => 'op_user_fields',
      'weight' => 2,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'schools' => array(
      'name' => 'Schools',
      'machine_name' => 'schools',
      'description' => 'List of school names from UCSF Profiles',
      'hierarchy' => 1,
      'module' => 'op_user_fields',
      'weight' => 2,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
